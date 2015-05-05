{
  "targets": [
    {
      "target_name": "mediaGalleries",
      "sources": [
        "src/mediaGalleries.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "conditions": [
        [
          "OS==\"win\"",
          {
            "sources": [
              "src/mediaGalleries_windows_desktop.cc"
            ],
            "configurations": {
              "Debug": {
                "defines": ["WIN32"],
                "msvs_settings": {
                  "VCCLCompilerTool": {
                    "RuntimeLibrary": 3,
                    "ExceptionHandling": 1,
                    "AdditionalOptions": [
                      "/EHsc"
                    ]
                  }
                }
              },
              "Release": {
                "defines": ["WIN32"],
                "msvs_settings": {
                  "VCCLCompilerTool": {
                    "RuntimeLibrary": 2,
                    "ExceptionHandling": 1,
                    "AdditionalOptions": [
                      "/EHsc"
                    ]
                  }
                }
              }
            }
          }
        ],
        [
          "OS==\"linux\"",
          {
            "sources": [
              "src/linux/xdg-user-dirs.cc",
              "src/mediaGalleries_linux.cc"
            ],
            "cflags_cc": [
              "-fexceptions"
            ]
          }
        ]
      ]
    }
  ]
}
