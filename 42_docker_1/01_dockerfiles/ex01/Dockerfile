# Teamspeak server docker container - V1 - 05.06.2019
FROM debian:latest

LABEL maintainer="Quentin Van Der perre <qvan-der@42.student.fr>"

ARG TEAMSPEAK_URL=https://files.teamspeak-services.com/releases/server/3.8.0/teamspeak3-server_linux_amd64-3.8.0.tar.bz2

RUN apt-get update \
	&& apt upgrade \
	&& apt-get install -y wget tar bzip2 \ 
	&& mkdir -p /home/teamspeak/server \
	&& chmod 777 /home/teamspeak \
	&& cd /home/teamspeak/server \
	&& wget "${TEAMSPEAK_URL}" -O server.tar.bz2 \
	&& tar -xf server.tar.bz2 --strip-components=1 \
	&& rm server.tar.bz2

WORKDIR /home/teamspeak/server/

EXPOSE 9987 1011 30033

ENTRYPOINT ./ts3server_minimal_runscript.sh
