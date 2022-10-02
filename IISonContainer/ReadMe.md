# IIS on Windows based Container
It's a simple tutorial to share how to run IIS on Windows based container, what logs we could collect for troubleshooting.

## Requirement
- Refer to [Windows IIS](https://hub.docker.com/_/microsoft-windows-servercore-iis) relesed by Microsoft

  ```bash
  docker pull mcr.microsoft.com/windows/servercore/iis
  ```
- Dockerfile
  ```bash
  FROM mcr.microsoft.com/windows/servercore/iis
  RUN powershell -NoProfile -Command Remove-Item -Recurse C:\inetpub\wwwroot\*
  WORKDIR /inetpub/wwwroot
  COPY content/ .
  ```
- Run it by PowerShell with Admin
  ```bash
  Enable-WindowsOptionalFeature -Online -FeatureName $("Microsoft-Hyper-V", "Containers") -All
  ```
- Siwtch Docker to Windows Container mode
## Build and Run
- Clone this project and navigate to IISonContainer folder.
  ```bash
  git clone https://github.com/Victor-Yao/TechTalkDemo.git
  ```
- Build and Run image
  ```bash
  docker build -t iis-site .
  docker run -d -p 8000:80 --name my-running-site iis-site
  ```
- Website URL
  - http://localhost:8000/
  - http://{ip}
    ```bash
    docker inspect -f "{{ .NetworkSettings.Networks.nat.IPAddress }}" my-running-site
    ```

## Configuration
- [appcmd](https://learn.microsoft.com/en-us/iis/get-started/getting-started-with-iis/getting-started-with-appcmdexe)
- copy applicationHost.config and web.config to on premise IIS server and configure by IIS manager.

## Enable Freb
- Install tracing module by [DISM](https://learn.microsoft.com/en-us/iis/install/installing-iis-85/installing-iis-85-on-windows-server-2012-r2#install-iis-85-using-dism)
  ```bash
  DISM.EXE /enable-feature /online /featureName:IIS-HttpTracing
  ```
- Add trace rule and enable by appcmd or IIS manager.

## Logs
- Windows event log
  Collect by [wevtutil](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/wevtutil)
  ```bash
  # Run in container
  wevtutil epl application c:\logs\application.evtx
  wevtutil epl system c:\logs\system.evtx
  ```

- The location of IIS log and httperr log are the same with IIS in on premise windows.
- use [Sysinternals for Nano](https://learn.microsoft.com/en-us/sysinternals/downloads/) to collect diagnostic logs, like memory dump.
  ```bash
  # Run in container
  procdump64 -ma -accepteula <PID>
  ```

