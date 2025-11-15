import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class LAB_2 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("./myData1.txt"));
        FileWriter fw = new FileWriter("./newFile.txt");
        String inStr;

        while (true) {
            inStr = br.readLine();
            if (inStr == null)
                break;
            fw.write(inStr + "\n");
        }
        br.close();
        fw.close();
    }
}
