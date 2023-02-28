#!/bin/sh
ifconfig -a | grep -Eo '([a-z0-9]{2}:){5}[a-z0-9]{2}'
