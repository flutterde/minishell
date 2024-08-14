# Minishell

Welcome to the `minishell` project, a simple shell implementation created as part of the 42 coding school curriculum. This project aims to replicate the basic functionality of a Unix shell, including command execution, piping, and redirection.

## Repository

You can find the repository here: [minishell](https://github.com/flutterde/minishell).

## Features

- Command execution
- Pipes (`|`)
- Redirection (`<`, `>`)
- Variable expansion
- Environment management

## Installation

To build and run `minishell`, you'll need the `readline` library. Follow these steps to set it up on macOS using Homebrew:

1. **Install `readline`**:

   ```sh
   brew install readline
   ```

2. **Link `readline`**:

   ```sh
   brew link readline --force
   ```

3. **Set up environment variables**:

   Update your environment variables to include the path to `readline`. Replace `$USER` with your actual username or ensure the path is correct for your system.

   ```sh
   export LDFLAGS="-L$(brew --prefix readline)/lib"
   export CPPFLAGS="-I$(brew --prefix readline)/include"
   ```

4. **Clone the repository**:

   ```sh
   git clone https://github.com/flutterde/minishell.git
   cd minishell
   ```

5. **Build the project**:

   Run `make` in your terminal at the root folder of the project.

## Usage

Once built, you can run `minishell` from the command line. Simply execute the binary to start the shell:

```sh
./minishell
```

## Contributing

Feel free to fork the repository and submit pull requests with improvements or bug fixes. Please ensure that any changes adhere to the project's coding standards and include appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or issues, please open an issue on the GitHub repository or contact [flutterde@gmail.com](mailto:flutterde@gmail.com).

Happy coding!

```

Feel free to adjust the contact information and any other specifics to better suit your needs.
