#!/bin/bash

DC = srcs/docker-compose.yaml
ENV = srcs/.env

all: volumes
	@docker-compose -f $(DC) --env-file $(ENV) up --detach

build: volumes
	@docker-compose -f $(DC) --env-file $(ENV) up --detach --build

volumes:
	@if [ ! -d /home/$(USER)/data/database ]; then \
		mkdir -p /home/$(USER)/data/database; \
	fi
	@if [ ! -d /home/$(USER)/data/wordpress ]; then \
		mkdir -p /home/$(USER)/data/wordpress; \
	fi

stop: 
	@docker-compose -f $(DC) --env-file $(ENV) stop

down:
	@docker-compose -f $(DC) --env-file $(ENV) down

fclean:
	@docker stop $$(docker ps --all --quiet)
	@docker system prune --all --force --volumes
	@if [ -d /home/$(USER)/data ]; then \
		sudo rm -rf /home/$(USER)/data; \
	fi

re:	fclean all

.PHONY:	all build volumes stop down fclean re
