FROM ruby:latest
RUN apt-get update && apt upgrade -y && apt-get install -y nodejs sqlite3

LABEL maintainer="Quentin Van Der perre <qvan-der@42.student.fr>"

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000

ONBUILD RUN bundler install
