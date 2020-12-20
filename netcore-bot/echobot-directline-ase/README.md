# Sample - enable Direct-Line app service extension in Netcore bot service

## Description

This sample refers [Direct Line App Service Extension protocol](https://docs.microsoft.com/en-us/azure/bot-service/bot-service-channel-directline-extension-net-bot?view=azure-bot-service-4.0) to enable DL ASE and run it in WebChat.

## How to enable DL ASE

1. ### Changing in netcore Project

    ![Insert code in netcore startup.cs](./images/netcore_startup.png "Insert code in netcore startup.cs")  

1. ### Changing in Portal

    - Enable direct-line channel. Then reval and copy "App Service Extension Keys".
      ![Change in portal](./images/appServiceExtensionKeys.png "copy extenstion key")  

    - Open "Configuration" in app sergice settings
      New "DirectLineExtensionKey" under Application Settings and assign "App Service Extension Keys" to value.
      ![Change in portal](./images/directLineExtensionKey.png "add extenstion key")  

    - Make sure websockets is on under general settings
      ![Change in portal](./images/websockets.png "enable websocket")  

1. ### Test DL-ASE if it's actived

    Browser https://<your_appService>.azurewebsites.net/.bot and confirm whether the result is good as below,  
{"v":"123","k":true,"ib":true,"ob":true,"initialized":true}  

- If **"ib" and "ob"** are false  
    One possible cause is the bot service is not wake up. You can chat it via test in webchat and again.
- If **"k" or "initialized"** is false  
    Please check [this sections](https://docs.microsoft.com/en-us/azure/bot-service/bot-service-channel-directline-extension-net-bot?view=azure-bot-service-4.0#confirm-direct-line-app-extension-and-the-bot-are-configured)

- Received **"HTTP Error 500.34 - ANCM Mixed Hosting"**  
    The cause is bot serivce uses inprocess hosting model. To configure it run as outofprocess model. The [Troubleshooting](https://docs.microsoft.com/en-us/azure/bot-service/bot-service-channel-directline-extension-net-bot?view=azure-bot-service-4.0#troubleshooting) section describes this error and provides a [solution](https://docs.microsoft.com/en-us/aspnet/core/host-and-deploy/aspnet-core-module?view=aspnetcore-3.1&preserve-view=true#out-of-process-hosting-model).  
    However, in my test lab, the outofprocess model has to be set in web.config and *.csproj together to fix this error.
    ![Change in portal](./images/netcore_csproj.png "enable websocket")
    ![Change in portal](./images/netcore_webconfig.png "enable websocket")

## How to use DL-ASE in the web page chat

- Fetch your DL-ASE token

    ```js
    const res = await fetch('https://<your_appService>.azurewebsites.net/.bot/v3/directline/tokens/generate', {
            method: 'POST',
            headers: {
              'Authorization': 'Bearer <your directline secret key>'
            }
          });

          const { token } = await res.json();
    ```

- Render webchat adapter with Direct-Line ASE token

    ```js
    window.WebChat.renderWebChat(
        {
          directLine: await window.WebChat.createDirectLineAppServiceExtension({
            domain: 'https://<your_appService>.azurewebsites.net/.bot/v3/directline',
            token
          })
        },
        document.getElementById('webchat')
      );
      ```

The completed code is in index.html.

## How to run sample code

1. clone this project  
1. Navigate to `/BotServiceSamples/netcore-bot/echobot-directline-ase/` in command line  
1. Run `npx serve`  
1. Browse to http://localhost:5000/