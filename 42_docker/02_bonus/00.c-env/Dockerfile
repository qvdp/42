FROM	ubuntu:latest

LABEL	maintainer="Quentin VAN DER PERRE<qvan-der@student.42.fr>"

RUN	apt update \
	&& apt upgrade -y  \
	&& apt-get install -y build-essential vim git

RUN	git clone https://github.com/qvdp/docker-c-env.git /opt/app \
	&& cd /opt/app \
	&& cd libft && make re && cd .. \
	&& sh compilator

WORKDIR /opt/app

RUN ./hello_world
