let describe: (string, list(Web_test.Test.t)) => Web_test.Suite.t =
  (description, tests) => Web_test.Suite.{description, tests};

let it: (string, unit => Web_test.Test.status) => Web_test.Test.t =
  (name, test) => Web_test.Test.{name, f: test};
