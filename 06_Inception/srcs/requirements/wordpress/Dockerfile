FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache \
    wget \
    mariadb-client \
    mysql-client \
    curl \
    unzip \
    php81 \
    php81-phar \
    php81-curl \
    php81-dom \
    php81-exif \
    php81-fileinfo \
    php81-fpm \
    php81-mbstring \
    php81-mysqli \
    php81-openssl \
    php81-xml \
    php81-zip && \
    # PHP-FPM process will now listen on port 9000 on all available network interfaces for incoming FastCGI requests
    sed -i "s/listen = 127.0.0.1:9000/listen = 9000/g" /etc/php81/php-fpm.d/www.conf && \
    # Download the WP-CLI
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

RUN wget https://wordpress.org/latest.zip && unzip latest.zip && cp -rf wordpress/* . && rm -rf wordpress latest.zip

COPY conf/wordpress.sh .

RUN chmod a+x ./wordpress.sh && chmod -R 0777 wp-content/

CMD ["./wordpress.sh"]
