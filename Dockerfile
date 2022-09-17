#https://hub.docker.com/layers/munken/build-essential/debian-wheezy-gcc/images/sha256-55773872885f8056dc40bc701aa70fd297e07fa3ddbf5b150a66c8878e63fd70?context=explore

FROM munken/build-essential:debian-wheezy-gcc

RUN apt-get update ;\
	# \apt-get install manpages-dev; \
	apt-get install build-essential;