FROM debian:bullseye

# install mariadb
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server

# move and set permissions for init script
COPY ./conf/mdb-init.sh /mdb-init.sh
RUN chmod +x /mdb-init.sh

# expose relevant ports
EXPOSE 3306

# run the init script
ENTRYPOINT ["./mdb-init.sh"]