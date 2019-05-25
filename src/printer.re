let print_results: list(Web_test.Test.test_result) => unit =
  results => {
    results
    |> List.map(status =>
         switch (status) {
         | Web_test.Test.Success => "OK\n"
         | Web_test.Test.Failure(error) => "Failed with \"" ++ error ++ "\"\n"
         }
       )
    |> List.iter(print_string);
  };
