<<<<<<< HEAD
# Caesar Vigenère Encryptor;
<p>Simple tool to encrypt/decrypt using ceasar or vigenere encryption algorithms</p>

<h2>Examples</h2>
Let's say you have a input.txt file that you want to encrypt using the ceasar cipher.
<ol>
  <li>Choose an ASCII character out of 255. This is the key so don't tell anyone else. I choose: 'z'</li>
  <li>Think of an filename for the encrypted data. For example: encrypted.txt</li>
  <li> Now you can encrypt input.txt: <code>./test caesar encrypt input.txt encrypted.txt z</code></li>
  <li> To decrypt the file: <code>./test caesar decrypt encrypted.txt decrypted.txt z</code></li>
 </ol>
<br>
<p>This uses 'z' as the key. You can use any ASCII character as the key.</p>
<br>
  <h2>Caution!</h2>
  
  <p>This software probably has bugs and security flaws because it can be bruteforced because each byte is encoded with the same key. It is not save to use this software to encrypt sensitive data. I am not responsible for any damages done by the software in this repository
  </p>
=======
# Caesar Vigenère Encryptor;
<p>Simple tool to encrypt/decrypt using ceasar or vigenere encryption algorithms</p>

<h2>Examples</h2>
Let's say you have a input.txt file that you want to encrypt using the ceasar cipher.
<ol>
  <li>Choose an ASCII character out of 255. This is the key so don't tell anyone else. I choose: 'z'</li>
  <li>Think of an filename for the encrypted data. For example: encrypted.txt</li>
  <li> Now you can encrypt input.txt: <code>./test caesar encrypt input.txt encrypted.txt z</code></li>
  <li> To decrypt the file: <code>./test caesar decrypt encrypted.txt decrypted.txt z</code></li>
 </ol>
<br>
<p>This uses 'z' as the key. You can use any ASCII character as the key.</p>
<br>
<br>
<p>You can do something similar using the vigenere cipher here u can also take any file as a key for encryption here u dont need only a key from ascii:
<code>./encryptor vigenere encrypt input.jpg output.jpg keyfile.mp4</code>
<code>./encryptor vigenere decrypt output.jpg decrypt.jpg keyfile.mp4</code>
  But this time, choose a file as the key instead of a single ASCII character. Make sure that this file is kept secret. 
  Alongside a file, you could also use any integer value between 0 and 2^64-1.
  </p>
Any file type can be used. Note that a larger key file is harder to crack, but this is limited to the input file size.
<br>

<h2>How does Vigenere encryption work?</h2>
  <p>
Vigenere is comparable with the Ceasar encryption, except that the key changes for every byte. Instead of applying one key to all the bytes, a keyfile is used where the bytes in the file are used for encryption and decryption. The first byte in the input is encrypted with the first byte of the keyfile, the second byte in the input is encrypted with the second byte of the keyfile and so on. When the input file is larger than the keyfile, the keyfile is repeated. This reduces safety because it means that some bytes are encrypted with the same values at a fixed distance. To solve this, the key file should be the same size or longer than the input file.
  </p>

  <h2>Caution!</h2>
  <p>This software probably has bugs and security flaws because it can be bruteforced because each byte is encoded with the same key. It is not save to use this software to encrypt sensitive data. I am not responsible for any damages done by the software in this repository
  </p>
>>>>>>> b13cdf964f8e998a1cf474d6d87d89eabb703717
