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
        ["OS==\"win\"", {
          "sources": [
            "src/mediaGalleries_windows_desktop.cc"
          ]
        }],
        ["OS==\"linux\"", {
          "sources": [
            "src/linux/xdg-user-dirs.cc",
            "src/mediaGalleries_linux.cc"
          ]
        }]
      ]
    }
  ]
}
