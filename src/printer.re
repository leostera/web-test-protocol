open Web_test.Test;

let print_results: Web_test.Suite.results => unit =
  suite => {
    print_string("# " ++ suite.description ++ "\n");
    suite.results
    |> List.map(({test, status}) =>
         switch (status) {
         | Web_test.Test.Successful => test.name ++ " OK\n"
         | Web_test.Test.Failed(error) =>
           test.name ++ " failed with \"" ++ error ++ "\"\n"
         }
       )
    |> List.iter(print_string);
  };
