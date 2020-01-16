#include <iostream>
using namespace std;

int main()
{
  int n;//number of case
  cin>>n;
  for(int i =1;i<=n;i++)
  {
      int s;
      cin>>s>>ws;
      string engine_name;
      string engine_names_list[s];
      int first_line[s];
      int number_of_repatation[s];
      for(int j=0;j<s;j++)
      {
          getline(cin,engine_name);
          engine_names_list[j]=engine_name;
          first_line[j]=101;
          number_of_repatation[j]=0;
      }
      int q;
      int large =0;
      cin>>q>>ws;
      string quireis[q];
      string user_input;
      for(int k=0;k<q;k++)
      {
          getline(cin,user_input);
          quireis[k]=user_input;
          for(int j=0;j<s;j++)
          {
              if(engine_names_list[j]==user_input)
              {
                  number_of_repatation[j]+=1;
                  if(number_of_repatation[j]==1)
                  {
                    first_line[j] = k;
                    if(k>large)
                    {
                        large =k;
                    }
                  }
                  break;

            }
          }
      }
    int number_of_switch=0;
    string engine_in_use = engine_names_list[0];
    for(int j=0;j<s;j++)
    {
        if(first_line[j]==101)
        {
            engine_in_use=engine_names_list[j];
            break;
        }
        else if(first_line[j]==large)
        {
            engine_in_use=engine_names_list[j];
        }

    }
    int index_break=0;
    for(int k=0;k<q;k++)
    {
        large =0;
        if(quireis[k]==engine_in_use)
        {
            number_of_switch++;
            index_break =k;
            for(int j =0;j<s;j++)
            {
                int counter=1;
                if(engine_names_list[j]!=engine_in_use)
                {
                first_line[j]=101;
                for(int m=k;m<q;m++)
                {
                    if(quireis[m]==engine_names_list[j])
                    {
                        if(counter==1)
                        {
                            first_line[j]=m;
                            if(m>large)
                            {
                                large=m;
                            }
                            counter++;

                        }
                    }
                }
                }
                else
                {
                    first_line[j]=102;
                }

            }
             for(int j=0;j<s;j++)
             {
                if(engine_in_use !=engine_names_list[j])
                {
                if(first_line[j]==101)
                {
                    engine_in_use = engine_names_list[j];
                    break;
                }
                else if(first_line[j]==large)
                {
                    engine_in_use = engine_names_list[j];

                }
                }
             }
            }



    }
    cout<<"Case #"<<i<<": "<<number_of_switch<<endl;


  }
  return 0;




}
