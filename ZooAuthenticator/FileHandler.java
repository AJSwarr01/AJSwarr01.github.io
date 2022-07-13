package zooauthenticator;

import java.io.*;

public class FileHandler {
    
    public static String[] readFile(String fileName) 
            throws Exception, IOException {
        if(fileName == null) {
            throw new Exception("File name cannot be NULL.");
        } else {
            File rawHandle = null;
            
            String line = null;
            
            StringWriter contents = null;
            
            FileReader fileHandle = null;
            BufferedReader reader = null;
            
            try {
                rawHandle = new File(fileName);
                
                if(!rawHandle.exists()) {
                    throw new IOException("File " + fileName + " not found.");
                } else if(!rawHandle.canRead()) {
                    throw new IOException("Cannot read file " + fileName + ".");
                } else {
                    fileHandle = new FileReader(fileName);
                    reader = new BufferedReader(fileHandle);
                    
                    contents = new StringWriter();
                    
                    while((line = reader.readLine()) != null) {
                        contents.append(line);
                        
                        if(!contents.toString().endsWith("\n")) {
                            contents.append('\n');
                        }
                    }
                }
            } catch (IOException ioe) {
                throw ioe;
            } catch (Exception e) {
                throw e;
            } finally {
                if(reader != null) {
                    reader.close();
                }
                
                if(fileHandle != null) {
                    fileHandle.close();
                }
            }
            
            return (contents == null) ? null : contents.toString().split("\n");
        }
    }
}
