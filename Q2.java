import java.util.ArrayList;
import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {
        int n;
        Scanner sc=new Scanner(System.in);
        n=Integer.parseInt(sc.nextLine());
        ArrayList<Integer> wait=new ArrayList<>(200000);
        ArrayList<String> name=new ArrayList<>(200000);
        ArrayList<String> wait_time1=new ArrayList<>(200000);
        int show_counter=0;
        int counter = 0;

        String line;
        String temp;
        int showindex=0;
        for (int i = 0; i <n ; ++i) {
            line=sc.nextLine();
            String [] line1 = line.split(" ");
            temp=line1[0];
            if(temp.contains("t")){

                int wait_time=Integer.parseInt(line1[1]);

                while (wait_time!=0&&wait.size()!=0){
//                cout<<wait_time<<wait[counter-1]<<endl;
                    if(wait_time==wait.get(wait.size()-1)){
                        wait.remove(wait.size()-1);
                        name.remove(name.size()-1);
//                        showindex=wait.size()-1;
//                        counter--;
                        wait_time=0;

                    }
//                cout<<wait_time<<wait[counter-1]<<endl;
                   else if(wait_time<wait.get(wait.size()-1)){
                        wait.set(wait.size()-1,wait.get(wait.size()-1)-wait_time);
//                        showindex=wait.size()-1;
                        wait_time=0;
                    }
//                cout<<wait_time<<wait[counter-1]<<endl;
                    else if(wait_time>wait.get(wait.size()-1)){

                        wait_time-=wait.get(wait.size()-1);
                        wait.remove(wait.size()-1);
                        name.remove(name.size()-1);

//                        showindex=wait.size()-1;
//                        counter--;

                    }
//                cout<<wait_time<<wait[counter-1]<<endl;
                }
//            cout<<counter<<endl;
                if(wait.size()==0){
                    wait_time1.add("main");
                    show_counter++;
//                    wait_time1[show_counter++]="main";
                }
                else{
                    wait_time1.add(name.get(wait.size()-1));
                    show_counter++;
//                    wait_time1[show_counter++]=name[showindex-1];
                }

            }
            if(temp.contains("i")) {
                name.add(temp);
//                name.set(counter,temp);
                wait.add(Integer.parseInt(line1[1]));

//                showindex++;
//            cout<<counter<<endl;
            }
        }
        for (int j = 0; j <show_counter ; ++j) {
            System.out.println(wait_time1.get(j));

        }


    }
}
