#!/bin/bash

chmod +rx models.sh

source ./models.sh

checkDocker

issuLicense

pullNginx

runContainer

cpServerFCGI

cpNginxConf
