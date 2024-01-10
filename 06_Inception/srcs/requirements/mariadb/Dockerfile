# Build a Docker image based on Alpine Linux version 3.18
FROM alpine:3.18

# set up the MariaDB Docker container
ARG MYSQL_DATABASE MYSQL_ROOT_PASSWORD MYSQL_USER MYSQL_PASSWORD

# Update and upgrade install 'mariadb' and 'mariadb-client' packages without caching
RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client

# incoming client connections on port 3306
EXPOSE 3306

# Copy 'mariadb.sh' to MariaDB Docker container's directory.
COPY conf/mariadb.sh .

RUN sh mariadb.sh && rm mariadb.sh

# Set Dockerfile user to 'mysql' for security, limiting access.
USER mysql

# Set MariaDB container to start 'mysqld' by default.
CMD ["mysqld"]
