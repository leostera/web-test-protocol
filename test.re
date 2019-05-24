open Dsl;

describe(
  "Some Suite",
  [
    it("true is true", () =>
      switch (true === true) {
      | true => Web_test.Test.Successful
      | _ => Web_test.Test.Failed("true wasn't true")
      }
    ),
    it("false is not true", () =>
      switch (false === false) {
      | true => Web_test.Test.Failed("Holy moly, we're in trouble!")
      | _ => Web_test.Test.Successful
      }
    ),
  ],
)
|> Web_test.run_suite
|> Printer.print_results;
