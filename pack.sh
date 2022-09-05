#!/bin/bash

echo "Packing task $TASK...";
echo "Enumerating task files...";
FILES=$(git ls-files | grep $TASK/ | tr '\n' ' ');
echo "Packing $(echo $FILES | tr -cd ' ' | wc -c) files...";
tar -czvf solution$TASK.tar.gz $FILES;
