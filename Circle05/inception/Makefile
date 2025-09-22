DOCKER_COMPOSE = ./srcs/docker-compose.yml
MDB_DIR = /home/justyn/data/mariadb
WP_DIR = /home/justyn/data/wordpress

all: dirs build up

dirs:
		mkdir -p $(WP_DIR)
		mkdir -p $(MDB_DIR)

build:
		docker compose -f $(DOCKER_COMPOSE) build

up:
		docker compose -f $(DOCKER_COMPOSE) up -d

down:
		docker compose -f $(DOCKER_COMPOSE) down

start:
		docker compose -f $(DOCKER_COMPOSE) start

stop:
		docker compose -f $(DOCKER_COMPOSE) stop

status:
		docker ps

fclean:
		docker stop $$(docker ps -qa)
		docker rm $$(docker ps -qa)
		docker rmi -f $$(docker images -qa)
		docker volume rm $$(docker volume ls -q)
		docker network rm $$(docker network ls -q) 2>/dev/null || true
		rm -rf $(WP_DIR)
		rm -rf $(MDB_DIR)

re: fclean dirs build up