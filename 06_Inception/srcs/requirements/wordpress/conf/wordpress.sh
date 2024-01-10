#!/bin/sh

# https://github.com/WordPress/WordPress/blob/master/wp-config-sample.php
if [ ! -f "/var/www/wp-config.php" ]; then
	cat << EOF > /var/www/wp-config.php
<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', '$MYSQL_DATABASE' );

/** Database username */
define( 'DB_USER', '$MYSQL_USER' );

/** Database password */
define( 'DB_PASSWORD', '$MYSQL_PASSWORD' );

/** Database hostname */
define( 'DB_HOST', '$MYSQL_HOST' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
\$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */

/** Allow to change interface language during WordPress installation. */
define( 'FS_METHOD', 'direct' );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
EOF

    # Initialize the attempts and the maximum number of attempts counters
    attempts=0
    max_attempts=10

    # Wait for the MariaDB database container to be ready and exit if the maximum number of attempts is reached
    until mysql -h$MYSQL_HOST -u$MYSQL_USER -p$MYSQL_PASSWORD $MYSQL_DATABASE > /dev/null 2>&1
    do
        sleep 5
        attempts=$((attempts+1))
        if [ $attempts -eq $max_attempts ]; then
            echo "Maximum attempts reached! MariaDB server is not ready, exiting..."
            exit 1
        fi
        echo "Waiting for MariaDB server to be ready... Attempt $attempts of $max_attempts"
    done

    # MariaDB is ready then install WordPress and create a user
    # https://developer.wordpress.org/cli/commands/core/
    # https://developer.wordpress.org/cli/commands/user/
    echo "MariaDB server is ready, proceeding with WordPress installation..."
    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
    wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=$WP_USER_ROLE --allow-root
    wp post delete 2 --force --allow-root
    echo "WordPress installation finished!"

else

    # Skip the installation if wp-config.php file already exists
    echo "WordPress is already installed. Skipping installation."

fi

# PHP-FPM process will now listen on port 9000 on all available network interfaces for incoming FastCGI requests
sed -i "s/listen = 127.0.0.1:9000/listen = 9000/g" /etc/php81/php-fpm.d/www.conf

# Start PHP-FPM in foreground
exec php-fpm81 -F
