# Vim app docker container - V1 - 05.06.2019
FROM alpine:latest

LABEL maintainer="Quentin Van Der perre <qvan-der@42.student.fr>"

# Install vim
RUN apk add vim

# Set the workdir as the root of machine
WORKDIR /

ENTRYPOINT vim
