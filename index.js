var api = require('./build/Release/mediaGalleries');

console.log(JSON.stringify(api));

module.exports = {
  getPictureGalleries: function () {
      return new Promise(function (resolve, reject) {
          api.getPictureGalleries(resolve, reject);
      });
  }
};