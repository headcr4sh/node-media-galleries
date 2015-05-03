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
        }]
      ]
    }
  ]
}