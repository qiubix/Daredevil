FROM ubuntu:14.04
#COPY . /usr/src/myapp
#WORKDIR /usr/src/myapp
#RUN gcc -o myapp main.c
#CMD ["./myapp"]
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
RUN apt-get update
