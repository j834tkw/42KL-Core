FROM debian:bullseye

# install dependencies for wordpress
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y curl php php7.4-fpm php-mysql mariadb-client

# move and set permissions for init script
COPY ./tools/wp-init.sh /wp-init.sh
RUN chmod +x wp-init.sh

# expose relevant ports
EXPOSE 9000 3306

# run the init script
ENTRYPOINT ["./wp-init.sh"]