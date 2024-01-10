FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache nginx && apk add --no-cache openssl

# https://www.baeldung.com/openssl-self-signed-cert
RUN openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/abeaugra.42.fr.key -out /etc/ssl/certs/abeaugra.42.fr.crt -subj "/C=FR"

# Accept incoming connections on port 443 used for HTTPS traffic when Nginx service is open
EXPOSE 443

# Start NGINX in container with '-g', 'daemon off' option
CMD ["nginx", "-g", "daemon off;"]
