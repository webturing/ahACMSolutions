import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
         
 
        while (cin.hasNext()) {
             int n = cin.nextInt();
                int m = cin.nextInt();
                int arr[] = new int[n];
                int max = 0;
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    arr[i] = cin.nextInt();
                    max = Math.max(max, arr[i]);
                    sum += arr[i];
                }
                int left = max, right = sum;
                int best = sum;
            while(left<=right)
            {
                int mid=(left+right)/2;
                int total=0;
                int tmp=0;
                for(int i=0;i<n;i++)
                {
                    if(tmp+arr[i]>mid)
                    {
                        total++;
                        tmp=arr[i];
                    }else {
                        tmp+=arr[i];
                    }
                     
                }
                if(tmp!=0)
                {
                    total++;
                }
                if(total<=m)
                {
                    right=mid-1;
                    best=mid;
                }
                else
                {
                    left=mid+1;
                }
                 
            }
             
             
            System.out.println(best);
        }
     
     
        cin.close();
    }
 
}