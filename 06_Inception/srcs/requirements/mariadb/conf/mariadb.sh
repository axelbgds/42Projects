#!/bin/bash

# Check if the directory '/var/run/mysqld' exists and create it if it doesn't exist : store + chown
if [ ! -d "/var/run/mysqld" ]; then
        mkdir -p /var/run/mysqld
        chown -R mysql:mysql /var/run/mysqld
fi

# Create '/etc/my.cnf.d' if missing, set its owner to 'mysql:mysql', 
# for storing MySQL server config files.
if [ ! -d "/etc/my.cnf.d" ]; then
        mkdir -p /etc/my.cnf.d
        chown -R mysql:mysql /etc/my.cnf.d
fi

# Create a new configuration file '/etc/my.cnf.d/docker.cnf' for the MySQL or MariaDB server database
echo '[mysqld]' > /etc/my.cnf.d/docker.cnf
# perf
echo 'skip-host-cache' >> /etc/my.cnf.d/docker.cnf
echo 'skip-name-resolve' >> /etc/my.cnf.d/docker.cnf
# Tell the server to listen
echo 'bind-address=0.0.0.0' >> /etc/my.cnf.d/docker.cnf
# instruct the MariaDB server to allow connections from outside the container
sed -i "s/skip-networking/skip-networking=0/g" /etc/my.cnf.d/mariadb-server.cnf


# Create '/var/lib/mysql/mysql', set 'mysql:mysql' ownership, run 'mysql_install_db' with data/base dirs, RPM, and check errors.
if [ ! -d "/var/lib/mysql/mysql" ]; then
        chown -R mysql:mysql /var/lib/mysql
        mysql_install_db --user=mysql --datadir=/var/lib/mysql --basedir=/usr --rpm
        tempfile=`mktemp`
        if [ ! -f "$tempfile" ]; then
                return 1
        fi
fi

# Create a new database with user and priv and flush
if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
        cat << EOF > /tmp/create_db.sql
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
CREATE DATABASE $MYSQL_DATABASE CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$MYSQL_USER'@'%' IDENTIFIED by '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF
        /usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db.sql
        rm -f /tmp/create_db.sql
fi

# docker exec -it mariadb mysql -uabeaugra -p
# USE wordpress
# SHOW tables;
# SELECT * FROM wp_users;
