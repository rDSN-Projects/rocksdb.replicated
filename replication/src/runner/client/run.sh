#!/bin/bash

rm -rf coredump/ meta/ replica* log.* core.*
./rrdb config.ini -app client -app_index 1
