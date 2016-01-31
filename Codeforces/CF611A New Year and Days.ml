let (num, str) = Scanf.scanf "%d %s %s" (fun x y z -> x, z) in
    let ans =
        if str = "week" then
            match num with
                | 5 -> 53
                | 6 -> 53
                | _ -> 52
        else
            match num with
                | 30 -> 11
                | 31 -> 7
                | _ -> 12
    in Printf.printf "%d\n" ans;;
