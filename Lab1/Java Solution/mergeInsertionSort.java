import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class mergeInsertionSort{
    public static void main(String[] args){
        int[] nums = createArray();
    }

    static int[] createArray(){
        List<Integer> nums = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int input = sc.nextInt();
            nums.add(input);
        }

        sc.close();
        int[] arr = convertArrayListToArray(nums);
        return arr;
    }

    static int[] convertArrayListToArray(List<Integer> arrlist){
        int len = arrlist.size();
        int[] result = new int[len];

        for(int i = 0; i < len; i++){
            result[i] = arrlist.get(i);
        }

        return result;
    }
}