#!/bin/sh
DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
exec "$DIR/_emit.sh" translation-viewport "$@"
