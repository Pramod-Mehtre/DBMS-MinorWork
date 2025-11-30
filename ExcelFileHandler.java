import java.io.FileInputStream;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.apache.poi.ss.usermodel.*;

public class SimpleExcelRead {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("data.xlsx");
            Workbook wb = new XSSFWorkbook(fis);
            Sheet sh = wb.getSheetAt(0);

            for (Row r : sh) {
                for (Cell c : r) {
                    System.out.print(c.toString() + "   ");
                }
                System.out.println();
            }

            wb.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
