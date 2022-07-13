package zooauthenticator;
 
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
 
public class MD5Hash {
    private MessageDigest md;
   
    public String getMD5Hash (String original) {
        try {
            md = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException ex) {
    }
   
   
    md.update(original.getBytes());
    byte[] digest = md.digest();
    StringBuilder sb = new StringBuilder();
    for (byte b : digest) {
            StringBuilder append = sb.append(String.format("%02x", b & 0xff));
                              }
              
    return sb.toString();
 
    }
}