# https://hub.docker.com/_/microsoft-dotnet
FROM mcr.microsoft.com/dotnet/sdk:6.0

# install dotnet tool
ENV PATH $PATH:/root/.dotnet/tools
RUN dotnet tool install --global dotnet-ef

# copy csproj and restore as distinct layers
WORKDIR /source
COPY *.csproj .
RUN dotnet restore --use-current-runtime  

# copy everything else and build app
COPY . .
RUN dotnet publish -c Release -o /app

EXPOSE 80 443
RUN chmod +x ./entrypoint.sh
CMD /bin/bash ./entrypoint.sh