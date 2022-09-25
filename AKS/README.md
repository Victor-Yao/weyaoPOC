# MVCApp Demo
## Prerequisites
- Create a ACR registry. 

  ```bash
  az acr create --name yourImagesACR --sku Basic -g yourRG
  ```
- Create a AKS cluster

  ```bash
  az aks create --name yourAksCluster --node-count 2 --generate-ssh-keys --attach-acr yourImagesACR
  ```

## Deploy Applicatoin
- Build your image and upload it to your Registry
  ```bash
  docker tag mvcapp yourImagesACR.azurecr.io/mvcapp
  docker push yourImagesACR.azurecr.io/mvcapp
  ```
- Open mvcapp.yaml and replace weyaoimagesacr with yourImagesACR

- Deploy application
  ```bash
  kubectl apply -f mvcapp.yaml
  ```

- Delete application
  ```bash
  kubectl delete -f mvcapp.yaml
  ```