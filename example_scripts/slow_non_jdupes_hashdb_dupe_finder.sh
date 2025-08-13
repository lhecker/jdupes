#!/bin/sh

# This is a simple, stupid SHA1-based duplicate finder.
# It creates or updates a hash database in the current directory
# and uses simple shell commands to find duplicates.

DB=hashdb.txt
TF=$(mktemp)

# Recursively get all file names under this directory. If present in the
# hash database, don't hash, otherwise hash and add.
# WARNING: DOES NOT CHECK IF FILE HAS CHANGED UNLESS "recheck" IS REQUESTED!
if [ "$1" != "recheck" ]
	then
	# Add files, checking for database presence before hashing
	find . -type f -size +0 | while read -r X
		do grep -m 1 -qv "$X" $DB && sha1sum "$X"
	done >> $DB

	else
	find . -type f -size +0 | while read -r X
		do
		# Remove existing instances of this file from the database...
		grep -v "  $X\$" < $DB > $TF
		cat "$TF" > $DB
		# ...and add a new hash.
		grep -m 1 -qv "$X" $DB && sha1sum "$X"
	done >> $DB
fi

# Remove any stray duplicate entries
sort < $DB | uniq > $TF
cat $TF > $DB
rm -f $TF
# Display duplicates based on hash matches
uniq -D -w 40 < $DB
