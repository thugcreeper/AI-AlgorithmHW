package ntou.cs;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpStatus;
import org.apache.commons.httpclient.methods.GetMethod;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class GetMethodExample {

    private static final String TARGET_URL = "https://www.google.com/search?q=java";

    public static void main(String[] args) {
        HttpClient client = new HttpClient();
        GetMethod method = new GetMethod(TARGET_URL);

        try {
            int statusCode = client.executeMethod(method);

            if (statusCode == HttpStatus.SC_NOT_IMPLEMENTED) {
                System.err.println("The GET method is not implemented by this URI");                
                method.getResponseBodyAsString();
            } else {
                processResponse(method);
            }
        } catch (IOException e) {
            System.err.printf("Error: %s%n", e.getMessage());
        } finally {
            method.releaseConnection();
        }
    }

    private static void processResponse(GetMethod method) {
        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(method.getResponseBodyAsStream(), StandardCharsets.UTF_8))) {
            
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.printf("Error: %s%n", e.getMessage());
        }
    }
}