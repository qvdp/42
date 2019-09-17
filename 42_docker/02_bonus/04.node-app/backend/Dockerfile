# Sails app docker container - V1 - 05.07.2019
FROM node:10

LABEL maintener="Quentin Van Der perre <qvan-der@student.42.fr>"

# Install sails in the container
RUN npm -g install sails

# Set the workdir as the root the cloned app
WORKDIR /app
COPY . /app

EXPOSE 1337
