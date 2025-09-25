#!/bin/bash
tools=("dotnet-dump" "dotnet-counters" "dotnet-gcdump" "dotnet-coverage" "dotnet-monitor" "dotnet-trace" "dotnet-stack" "dotnet-symbol" "dotnet-sos" "dotnet-dsrouter")

for item in ${tools[@]}
do
    dotnet tool install $item --global
done 