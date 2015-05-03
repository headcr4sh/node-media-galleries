@ECHO OFF
SET HOME="%USERPROFILE%\.electron-gyp"
SET npm_config_disturl=https://atom.io/download/atom-shell
SET npm_config_target=0.25.2
SET npm_config_arch=x64
npm install
REM node-gyp rebuild --target=0.25.2 --arch=x64 --dist-url=https://atom.io/download/atom-shell