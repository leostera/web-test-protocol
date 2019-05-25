open Dsl;

describe(
  "Some Suite",
  [
    it("true is true", () =>
      switch (true === true) {
      | true => Web_test.Test.Success
      | _ => Web_test.Test.Failure("true wasn't true")
      }
    ),
    it("false is not true", () =>
      /** this will obviously fail! */
      switch (false === false) {
      | true => Web_test.Test.Failure("Holy moly, we're in trouble!")
      | _ => Web_test.Test.Success
      }
    ),
  ],
)
|> Web_test.run_suite
|> Printer.print_results;
