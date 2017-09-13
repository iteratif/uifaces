set path=;%path%;C:\Users\iteratif\Documents\Visual Studio 2015\Projects\iteratif\ThirdParty
for /r %%i in (*.png) do ( texconv.exe -f R8G8B8A8_UNORM -y %%~nxi )