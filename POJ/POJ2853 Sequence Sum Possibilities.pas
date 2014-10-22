program POJ2853;
var m,n,i,t,s:int64;
begin
        read(m);
        while m>0 do
        begin
                m:=m-1;
                t:=0;
                read(n);
                read(s);
                i:=1;
                while i<=70000 do
                begin
                        i:=i+1;
                        if((s*2-i*i+i)mod(2*i)=0)and(2*s-i*i+i>0) then 
                                begin
                                t:=t+1;
                                end
                        else
                                begin
                                if(2*s-i*i+i<=0) then begin break; end;
                                end;
                end;
                write(n);
                write(' ');
                writeln(t);
        end;
end.