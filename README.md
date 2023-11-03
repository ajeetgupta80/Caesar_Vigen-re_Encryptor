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
