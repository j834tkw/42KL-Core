FROM debian:bullseye

# install nginx and openssl
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y nginx openssl

# move and set permissions for init script
COPY ./tools/ngx-init.sh ./ngx-init.sh
RUN chmod +x ngx-init.sh

# move nginx.conf
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# create directories for ssl
RUN mkdir -p /etc/ssl/private
RUN chmod 700 /etc/ssl/private

# expose relevant ports
EXPOSE 443

# run the init script
ENTRYPOINT ["./ngx-init.sh"]