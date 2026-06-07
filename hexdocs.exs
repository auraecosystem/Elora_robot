def project do
  [
    app: :my-app,
    version: "0.1.0-dev",
    deps: deps(),

    # Docs
    name: "Elora_bot",
    source_url: "https://github.com/auraecosystem/Elora_robot",
    homepage_url: "http://Elora_robot.pm",
    docs: &docs/0
  ]
end

defp docs do
  [
    main: "readme", # can be changed to a module name, if you prefer
    logo: "path/to/logo.png",
    extras: ["README.md"]
  ]
end
