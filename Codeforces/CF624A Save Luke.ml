let (d, l, v1, v2) = Scanf.scanf "%f %f %f %f" (fun x y z w -> x, y, z, w)
    in Printf.printf "%.8f\n" ((l -. d) /. (v1 +. v2));;
