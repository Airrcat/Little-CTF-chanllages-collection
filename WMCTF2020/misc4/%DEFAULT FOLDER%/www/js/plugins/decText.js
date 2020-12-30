(function () {
    const crypto = require('crypto');
    const key = ''; //发布前删掉
    const defaultKey = crypto.createHash('md5').update(key).digest('hex');

    function aesEncrypt(data, key) {
        const cipher = crypto.createCipher('aes192', key);
        let c = cipher.update(data, 'utf8', 'hex');
        c += cipher.final('hex');
        return c;
    }

    function aesDecrypt(encrypted, key) {
        try {
            const decipher = crypto.createDecipher('aes192', key);
            let decrypted = decipher.update(encrypted, 'hex', 'utf8');
            decrypted += decipher.final('utf8');
            return decrypted;
        } catch (e) {
            return encrypted;
        }            
    }

    function getKey() {
        let outputKey = "";
        try {
            Decrypter.readEncryptionkey();

            for (i = 0; i < Decrypter._headerlength; i++) {
                outputKey += Decrypter._encryptionKey[i];
            }
        } catch (e) {
            outputKey = defaultKey;
        }
        return outputKey;
    }
    function decText(text) {
        try {
            return aesDecrypt(text, getKey());
        } catch (e) {
            return `Error: ${e}`;
        }
    }
    window.decText = decText;
})()