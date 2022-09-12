# Asp.Net Core demo

This is an asp.net mvc application and build as docker image. The image shared on [Docker Hub](https://hub.docker.com/r/weiyao666/aspnetcoredemo). This demo refers to [aspnetsample](https://github.com/dotnet/dotnet-docker/tree/main/samples/aspnetapp) and built on [asp.net runtime image](https://hub.docker.com/_/microsoft-dotnet-aspnet).

## Prerequisites

- Install [.NET SDK](https://dotnet.microsoft.com/download) version 6.0 or above

  ```bash
  # determine dotnet version
  dotnet --version
  ```
- Install [Docker](https://docs.docker.com/get-docker/) latest version

## Try to run this application
By default URL,  http://localhost:8080
1. Docker CLI
    ```bash
    docker pull weiyao666/aspnetcoredemo
    docker run -p 8080:80 --name mywebapp weiyao666/aspnetcoredemo
    ```
1. Docker Compose

    Download this [compose file](https://github.com/Victor-Yao/TechTalkDemo/tree/main/DockerComposeSample/docker-compose-aspnetcore.yml) and run it directly.

    ```bash
    docker compose -f docker-compose-aspnetcore.yml up -d --wait
    ```